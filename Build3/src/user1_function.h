
#ifndef USER1_FUNCTION_H_INCLUDED
#define USER1_FUNCTION_H_INCLUDED


typedef struct {
     int month;
     int day;
     int year;
}D;


typedef struct{

char id[20];
char name[20];
char fn[20];
char pass[20];
D date;
int gender;
int phone;
int social;
int dis;
int role;
char mun[30];
char vote[20];
}user;

int add_user(char * fileuser, user u );
int modify( char * fileuser, char id[20], user new );
int delete(char * fileuser, char id[20]);
user search(char * fileuser, char id[20]);
/*void display_user(GtkWidget *list);*/
void trier (char * fileuser);
void statmf (char * fileuser, float *pm, float *pf);
#endif // USER1_FUNCTION_H_INCLUDED

