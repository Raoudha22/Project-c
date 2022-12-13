#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "Functionpst1.h"


enum
{
    ID_PST,
    CAPACITY,
    GOUVERNORATE,
    MUNICIPALITY,
    ID_AGENT,
    COLUMNS
};

int add_pst(char *filename,Polling_station p)
{
    FILE * f=fopen("pstfile.txt","a");
    if (f!=NULL)
    {
        fprintf(f,"%d %d %s %s %s \n",p.id,p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
int modify_pst(char*filename,int id,Polling_station pstnew)
{
    int tr=0;
    Polling_station p;
    FILE * f=fopen("pstfile.txt","r");
    FILE * f2=fopen("pstnew.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %s \n",&p.id,&p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps)!=EOF)
            {
                if(p.id==id)
                    {
                        fprintf(f2,"%d %d %s %s %s \n",pstnew.id,pstnew.cov_adps,pstnew.gouv_addps,pstnew.mun_addps,pstnew.idta_addps);
                        tr=1;
                    }
                else
                        fprintf(f2,"%d %d %s %s %s \n",p.id,p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps);
            }
    }
    fclose(f);
    fclose(f2);
    remove("pstfile.txt");
    rename("pstnew.txt","pstfile.txt");
    return tr;
}
int delete_pst(char *filename,int id)
{
    int tr=0;
    Polling_station p;
    FILE* f=fopen("pstfile.txt","r");
    FILE* f2=fopen("pstnew.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %s \n",&p.id,&p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps)!=EOF)
        {
            if(p.id==id)
                tr=1;
            else
                fprintf(f2,"%d %d %s %s %s \n",p.id,p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps);
        }
    }
    fclose(f);
    fclose(f2);
    remove("pstfile.txt");
    rename("pstnew.txt","pstfile.txt");
    return tr;
}

Polling_station search_pst (char* filename,int id)
{
    Polling_station p;
    int tr=0;
    FILE *f=fopen("pstfile.txt","r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%d %d %s %s %s \n",&p.id,&p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps)!=EOF)
        {
            if(p.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        p.id=-1;
    return p;
}

int generate_id(char* filename)
{
    Polling_station p;
    int k = 0;
    int i;
    int T[3];
    do{
    for (i=0;i<3;i++)
    {
        T[i]=(rand() % 60);
        printf("%d",T[i]);
    }
    for (i = 0; i < 3; i++)
    k = 10 * k + T[i];
    search_pst ("pstfile.txt",k);
    }while(p.id!=-1);
    return k;
}

void display_pst (GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char id_pst[20];
    char capacity[20];
    char gouvernorate[20];
    char municipality[20];
    char id_agent[20];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_PST", renderer, "text", ID_PST, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("CAPACITY", renderer, "text", CAPACITY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer = gtk_cell_renderer_text_new();        
        column = gtk_tree_view_column_new_with_attributes("GOUVERNORATE", renderer, "text", GOUVERNORATE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("MUNICIPALITY", renderer, "text", MUNICIPALITY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_AGENT", renderer, "text", ID_AGENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        f = fopen("pstfile.txt", "r");
        if (f == NULL)
        {
            return;
        }
        else
        {
            f = fopen("pstfile.txt", "a+");
            while (fscanf(f, "%s %s %s %s %s \n ", id_pst,capacity,gouvernorate,municipality,id_agent) != EOF)
            {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter,ID_PST,id_pst,CAPACITY,capacity,GOUVERNORATE,gouvernorate,MUNICIPALITY,municipality,ID_AGENT,id_agent,-1);
            }
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
