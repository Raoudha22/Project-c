#ifndef FUNCTIONPST_H_INCLUDED
#define FUNCTIONPST_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
int  id;
int cov_adps;
char gouv_addps[30];
char mun_addps[30];
char idta_addps[30];
}Polling_station;
int add_pst(char *pstfile,Polling_station p);
int modify_pst(char*pstfile,int id,Polling_station pstnew);
int delete_pst(char *pstfile,int id);
Polling_station search_pst (char* pstfile,int id);
void nb_electors_Pst(char *filename);
float avg_age_of_agents(char * filename );
int generate_id(char* filename);
void display_pst (GtkWidget *liste);

#endif // FUNCTIONPST_H_INCLUDED

