#include<windows.h>                  
#include<sqlext.h> 
#include<stdio.h>
#include<string.h>
#define TEST_LEN 50
int main()
{
    int c;
    char ch='y';
    SQLINTEGER Amount,Creditcardno;
    SQLCHAR Name[TEST_LEN+1], Moviename[TEST_LEN+1], Showdate[TEST_LEN+1], Showtime[TEST_LEN+1], Theatre[TEST_LEN+1], Availability[TEST_LEN+1], MailID[TEST_LEN+1];
    HENV hEnv=NULL;
    HDBC hDBC=NULL;
    HSTMT hStmt=NULL;
    UCHAR szSqlStr[] = "insert into res(Name,Moviename,Showdate,Showtime,Theatre,Amount,Availability,MailID,Creditcardno) values(?,?,?,?,?,?,?,?,?)";UCHAR szSqlStr1[]="delete * from res where Name = ?";
UCHAR szSqlStr2[]="select * from res";
UCHAR szDSN[SQL_MAX_DSN_LENGTH]="ticket";
UCHAR *szUID=NULL;
UCHAR *szPasswd=NULL;
UCHAR szModel1[128];
UCHAR szModel2[128];
UCHAR szModel3[128];
UCHAR szModel4[128];
UCHAR szModel5[128];
UCHAR szModel6[128];
UCHAR szModel7[128];
UCHAR szModel8[128];
UCHAR szModel9[128];
SDWORD cbModel1;
SDWORD cbModel2;
SDWORD cbModel3;
SDWORD cbModel4;
SDWORD cbModel5;
SDWORD cbModel6;
SDWORD cbModel7;
SDWORD cbModel8;
SDWORD cbModel9;
SDWORD cbtest=SQL_NTS;
RETCODE retcode;
do
{
   printf("\n======================================="); 
   printf("\n   TICKET RESERVATION IN THEATRE SYSTEM");
   printf("\n=======================================\n");
    printf("1.Enter the ticket detail \n2.Delete the ticket detail\n3.Display the ticket detail\n\n");
    printf("Enter ur option......\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        printf("\n-----------------------------------------");
        printf("\nEnter the details");
        printf("\n-----------------------------------------");
        printf("\nEnter the Name:\t");
        scanf("%s",&Name);
        printf("\nEnter the Movie name:\t");
        scanf("%s",&Moviename);
        printf("\nEnter the Show date:\t");
        scanf("%s",&Showdate);
        printf("\nEnter the Show time:\t");
        scanf("%s",&Showtime);
        printf("\nEnter the Theatre name:\t");
        scanf("%s",&Theatre);
        printf("\nEnter the Amount:\t");
        scanf("%d",&Amount);
        printf("\nAvailability(y/n):\t");
        scanf("%s",&Availability);
        printf("\nEnter Mail ID:\t");
        scanf("%s",&MailID);
        printf("\nEnter Credit card No:\t");
        scanf("%d",&Creditcardno);        
        printf("\n-----------------------------------------");
//        SQLAllocEnv(&hEnv);
//        SQLAllocConnect(hEnv,&hDBC);
//        retcode=SQLConnect(hDBC,szDSN,SQL_NTS,szUID,SQL_NTS,szPasswd,SQL_NTS);
        if(retcode==SQL_SUCCESS||retcode==SQL_SUCCESS_WITH_INFO)
        {
//            retcode=SQLAllocStmt(hDBC,&hStmt);
//            retcode=SQLPrepare(hStmt,szSqlStr,sizeof(szSqlStr));
//SQLBindParameter(hStmt,1,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Name,0,&cbtest);       SQLBindParameter(hStmt,2,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Moviename,0,&cbtest);    SQLBindParameter(hStmt,3,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Showdate,0,&cbtest);
//SQLBindParameter(hStmt,4,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Showtime,0,&cbtest);
//SQLBindParameter(hStmt,5,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Theatre,0,&cbtest);
//SQLBindParameter(hStmt,6,SQL_PARAM_INPUT,SQL_C_LONG,SQL_INTEGER,1,0,&Amount,0,&Amount);
//SQLBindParameter(hStmt,7,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Availability,0,&cbtest);
///SQLBindParameter(hStmt,8,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,MailID,0,&cbtest);
//SQLBindParameter(hStmt,9,SQL_PARAM_INPUT,SQL_C_LONG,SQL_INTEGER,1,0,&Creditcardno,0,&Creditcardno);
//            retcode=SQLExecute(hStmt);
            printf("\n\n Detail is inserted.......... \n\n");
        }
        break;
    case 2:
        printf("\nDelete the detail\n");
//        SQLAllocEnv(&hEnv);
  //      SQLAllocConnect(hEnv,&hDBC);
    //    retcode=SQLConnect(hDBC,szDSN,SQL_NTS,szUID,
       //     SQL_NTS,szPasswd,SQL_NTS);
        if(retcode==SQL_SUCCESS||retcode==SQL_SUCCESS_WITH_INFO)
        {
            retcode=SQLAllocStmt(hDBC,&hStmt);
            retcode=SQLPrepare(hStmt,szSqlStr1,sizeof(szSqlStr1));
SQLBindParameter(hStmt,1,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_CHAR,TEST_LEN,0,Name,0,&cbtest);
            printf("\nEnter the Name\n");
            scanf("%s",&Name);
            retcode=SQLExecute(hStmt);
            printf("detail has been deleted\n\n");
        }
        break;
    case 3:
        printf("\nDisplay the detail\n");
        SQLAllocEnv(&hEnv);
        SQLAllocConnect(hEnv,&hDBC);
        retcode=SQLConnect(hDBC,szDSN,SQL_NTS,szUID,SQL_NTS,szPasswd,SQL_NTS);
        if(retcode==SQL_SUCCESS||retcode==SQL_SUCCESS_WITH_INFO)
        {
            retcode=SQLAllocStmt(hDBC,&hStmt);
            retcode=SQLPrepare(hStmt,szSqlStr2,sizeof(szSqlStr2));
            retcode=SQLExecute(hStmt);
            SQLBindCol(hStmt,1,SQL_C_CHAR,szModel1,sizeof(szModel1),&cbModel1);
            SQLBindCol(hStmt,2,SQL_C_CHAR,szModel2,sizeof(szModel2),&cbModel2);
            SQLBindCol(hStmt,3,SQL_C_CHAR,szModel3,sizeof(szModel3),&cbModel3);
            SQLBindCol(hStmt,4,SQL_C_CHAR,szModel4,sizeof(szModel4),&cbModel4);
            SQLBindCol(hStmt,5,SQL_C_CHAR,szModel5,sizeof(szModel5),&cbModel5);
            SQLBindCol(hStmt,6,SQL_C_CHAR,szModel6,sizeof(szModel6),&cbModel6);
            SQLBindCol(hStmt,7,SQL_C_CHAR,szModel7,sizeof(szModel7),&cbModel7);
            SQLBindCol(hStmt,8,SQL_C_CHAR,szModel8,sizeof(szModel8),&cbModel8);
            SQLBindCol(hStmt,9,SQL_C_CHAR,szModel9,sizeof(szModel9),&cbModel9);
            retcode=SQLFetch(hStmt);
            printf("\n\tName\tMoviename\tShowdate\tShowtime\tTheatre\tAmount\tAvailability\tMailID\tCreditcardno\n\n");
               while(retcode==SQL_SUCCESS||retcode==SQL_SUCCESS_WITH_INFO)
            {
               printf("\t%s\t%s\t\t%s\t\t%s\t\t%s\t%s\t%s\t\t%s\t%s\n", szModel1,szModel2,szModel3,szModel4,szModel5,szModel6,szModel7,szModel8,szModel9);
               retcode=SQLFetch(hStmt);
               }
        }
        break;    
        }
//flushall();
printf("\nDo u wan to cont (y/n)");
scanf("%s",&ch);
}
while(ch=='y');
return 0;
}
