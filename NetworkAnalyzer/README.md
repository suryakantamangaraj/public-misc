# S-Parameter Analysis

This project is a Flask application for analyzing S-parameter files (.s2p). It allows users to upload an S-parameter file, filter data by frequency range, and visualize various measurements such as Insertion Loss, Return Loss, and Phase Response.

## Features

- Upload and parse S-parameter (.s2p) files
- Filter data by start and stop frequency
- Visualize Insertion Loss, Return Loss, and Phase Response
- Display minimum, maximum, and average values of the selected measurement

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/your-repository.git
   cd your-repository
   ```

2. Create and activate a virtual environment:
   ```bash
   python3 -m venv venv
   source venv/bin/activate
   ```

3. Install the dependencies:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

1. Run the Flask application:
   ```bash
   python app.py
   ```

2. Open your web browser and go to `http://127.0.0.1:5000/`.

3. Upload an S-parameter file, set the frequency range, and select the measurement to analyze.

## Deployment

This project can be deployed using GitHub Actions and GitHub Pages. The workflow file is located in `.github/workflows/deploy.yml`.

### GitHub Actions Workflow

The GitHub Actions workflow is configured to deploy the site to GitHub Pages. Ensure you have a personal access token (PAT) with the necessary permissions added to your repository secrets as `PERSONAL_TOKEN`.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
