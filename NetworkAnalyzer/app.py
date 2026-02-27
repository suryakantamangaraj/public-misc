# static site generator like Frozen-Flask 
from flask_frozen import Freezer
from flask import Flask, render_template, request
import pandas as pd
import matplotlib.pyplot as plt
import io
import base64
import skrf as rf

app = Flask(__name__)
# add this for freezer
freezer = Freezer(app)


def parse_s2p(file):
    # Save the uploaded file to a temporary location
    temp_file_path = '/tmp/temp_s2p_file.s2p'
    file.save(temp_file_path)
    
    # Parse the s2p file using scikit-rf and return a DataFrame
    network = rf.Network(temp_file_path)
    data = pd.DataFrame({
        'Frequency': network.f,
        'S11': network.s[:, 0, 0],
        'S21': network.s[:, 1, 0],
        'S12': network.s[:, 0, 1],
        'S22': network.s[:, 1, 1]
    })
    return data

# Flask app routes and configurations
@app.route('/', methods=['GET', 'POST'])
def index():
    result = None
    graph = None
    if request.method == 'POST':
        file = request.files['s2p_file']
        start_freq = request.form.get('start_freq')
        stop_freq = request.form.get('stop_freq')
        measurement = request.form.get('measurement')

        data = parse_s2p(file)
        if start_freq:
            data = data[data['Frequency'] >= float(start_freq)]
        if stop_freq:
            data = data[data['Frequency'] <= float(stop_freq)]

        if measurement == 'Insertion Loss':
            values = data['S21']
        elif measurement == 'Return Loss':
            values = data['S11']
        elif measurement == 'Phase Response':
            values = data['S21'].apply(lambda x: complex(x).phase)
        else:
            values = data['S21']

        result = {
            'min': values.min(),
            'max': values.max(),
            'avg': values.mean()
        }

        plt.figure()
        plt.plot(data['Frequency'], values)
        plt.xlabel('Frequency')
        plt.ylabel(measurement)
        plt.title(f'{measurement} vs Frequency')
        img = io.BytesIO()
        plt.savefig(img, format='png')
        img.seek(0)
        graph = base64.b64encode(img.getvalue()).decode()

    return render_template('index.html', result=result, graph=graph)

if __name__ == '__main__':
    app.run(debug=True)
