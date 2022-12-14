#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Functionpst1.h"
#include "user1_function.h"


void
on_login_sign_clicked                  (GtkWidget       *object,
                                        gpointer         user_data)
{
		
	GtkWidget *affichage;
	GtkWidget *w1;
	GtkWidget *treeview;
	w1=lookup_widget(object,"Login");
	affichage= create_Administator ();
	gtk_widget_show(affichage);
	gtk_widget_hide(w1);
	treeview =lookup_widget(affichage, "list_polling");
	display_pst (treeview);
	
}


void
on_list_user_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_user_del_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_user_search_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_user_mod_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_user_add_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_list_elec_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_elec_add_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_elec_search_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_elec_del_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_elec_mod_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_list_polling_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkTreeIter iter;
    gchar *id_pst;
    gchar *capacity;
    gchar *gouvernorate;
    gchar *municipality;
    gchar *id_agent;
    Polling_station p;
    
    
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        FILE *f;
        f = fopen("selected.txt", "w");
        if (f != NULL)
        {
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id_pst, 1, &capacity, 2, &gouvernorate, 3, &municipality, 4, &id_agent, -1);
	    int id= atoi (id_pst);
	    int cap= atoi (capacity);
	    fprintf(f,"%d %d %s %s %s",id,cap,gouvernorate,municipality,id_agent);
	    /*strcpy(p.cov_adps,capacity);
	    strcpy(p.gouv_addps,gouvernorate);
	    strcpy(p.mun_addps,municipality);
	    strcpy(p.idta_addps,id_agent);
	    delete_pst("pstfile.txt",id);
	    display_pst ("list_polling");*/
	
        }
	fclose(f);
    }
}


void
on_polling_mod_clicked                 (GtkWidget      *object,
                                        gpointer         user_data)
{
	GtkWidget *mod;
	GtkWidget *w1;
	w1=lookup_widget(object,"Administator");	
	mod = create_Modify_polling_station();
	gtk_widget_show(mod);
	gtk_widget_hide(w1);
}


void
on_polling_search_clicked              (GtkWidget       *object,
                                        gpointer         user_data)
{
    Polling_station p;
    char msg[200];
    char idt[20],cap[20];
    
    GtkWidget *input_id;
    GtkWidget *output;
    
    input_id = lookup_widget(object, "searchpolling");
    output = lookup_widget(object, "searchpolling_label");
    strcpy(idt, gtk_entry_get_text(GTK_ENTRY(input_id)));
    int id = atoi ( idt );
    p = search_pst("pstfile.txt", id);
    sprintf(idt, "%d" , p.id);
    sprintf(cap, "%d" , p.cov_adps);
    if(p.id==-1)
    {
	
	gtk_label_set_text(GTK_LABEL(output), "No polling station with that id");
        
    }
    else
    {
	strcat(msg, "ID:");
        strcat(msg, idt);
        strcat(msg, " CAP:");
        strcat(msg, cap);
        strcat(msg, " GOUV:");
        strcat(msg, p.gouv_addps);
        strcat(msg, " MUNI");
        strcat(msg, p.mun_addps);
        strcat(msg, " AGENT:");
        strcat(msg, p.idta_addps);

        gtk_label_set_text(GTK_LABEL(output), msg);
	//put the search result in selected.txt
        FILE *f;
        f= fopen("selected.txt", "w");
        if (f!= NULL)
        {
            fprintf(f,"%d %d %s %s %s",p.id,p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps);
            fclose(f);
        }
    }
}


void
on_polling_add_clicked                 (GtkWidget       *object,
                                        gpointer         user_data)
{
	user u;	
	GtkWidget *Combobox3;
	FILE *f;
	int n,i;
	char agent[50][20];
	n=0;
	GtkWidget *add;
	GtkWidget *w1;
	w1=lookup_widget(object,"Administator");	
   	add = create_Add_polling_station();
   	gtk_widget_show(add);
	gtk_widget_hide(w1);
	Combobox3=lookup_widget(object,"addpolling_id");
	f=fopen("fileuser.txt","r");
	while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d %s %s\n",u.id,u.name,u.fn,u.pass,&u.date.day,&u.date.month,&u.date.year,&u.gender,&u.phone,&u.social,&u.dis,&u.role,u.mun,u.vote)!=EOF)
        { 
		if(u.role==2)
		{
		strcpy(agent[n],u.id);
		n++;
		}
	}
		for(i=0;i<n;i++)
		{
		gtk_combo_box_append_text (GTK_COMBO_BOX(Combobox3),(agent[i]));
		}
	
	
		
	
}


void
on_polling_del_clicked                 (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *affichage,*w1;
	GtkWidget *treeview;	
	Polling_station p;	
	FILE *f=fopen("selected.txt","r");

	while(fscanf(f,"%d %d %s %s %s \n",&p.id,&p.cov_adps,p.gouv_addps,p.mun_addps,p.idta_addps)!=EOF)
            {
                delete_pst("pstfile.txt",p.id);
	    }
	
	
	w1=lookup_widget(object,"Administator");
	affichage= create_Administator ();
	gtk_widget_show(affichage);
	gtk_widget_hide(w1);
	treeview =lookup_widget(affichage, "list_polling");
	display_pst (treeview);
}


void
on_adduser_date_day_selected           (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_adduser_date_next_month             (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_adduser_date_next_year              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_adduser_date_prev_month             (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_adduser_date_prev_year              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_adduser_sub_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_adduser_yes_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_adduser_no_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_adduser_female_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_adduser_male_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_adduser_conf_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_usermod_no_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_usermod_yes_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_usermod_female_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_usermod_male_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_usermod_confirm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_usermod_sub_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_addelecmang_date_day_selected       (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_addelecmang_date_next_month         (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_addelecmang_date_next_year          (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_addelecmang_date_prev_month         (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_addelecmang_date_prev_year          (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_addelecmang_resp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_addelecmang_conf_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_addelecmang_sub_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modelecmanag_date_day_selected      (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_modelecmanag_date_next_month        (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_modelecmanag_date_next_year         (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_modelecmanag_date_prev_month        (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_modelecmanag_date_prev_year         (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_modelecmang_cnf_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_modelecmang_resp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_modelecmang_ot_changed              (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_modelecmang_ot_insert_text          (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_modelecmang_ct_changed              (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_modelecmang_ct_insert_text          (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_modelecmang_sub_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_addelecmang_np_changed              (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_addelecmang_np_insert_text          (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_eleclist_date_day_selected          (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_eleclist_date_next_month            (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_eleclist_date_next_year             (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_eleclist_date_prev_month            (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_eleclist_date_prev_year             (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_eleclist_conf_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_eleclist_res_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_eleclist_sub_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_spinbutton1_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_spinbutton1_insert_text             (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


void
on_spinbutton2_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_spinbutton2_insert_text             (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{

}


int confirmradio=0;
void
on_addpolling_conf_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        confirmradio=1;
    }
}


void
on_addpolling_sub_clicked              (GtkWidget       *object,
                                        gpointer         user_data)
{
	Polling_station p;
	user u;
	GtkWidget *Cap;
	GtkWidget *Combobox1;
	GtkWidget *Combobox2;
	GtkWidget *Combobox3;
	GtkWidget *output;
	char agent[50][20];
	int i,n;
	FILE *f;
	
	
	Cap=lookup_widget(object,"addpolling_cap");
	output=lookup_widget(object,"addpolling_err");
	Combobox1=lookup_widget(object,"addpolling_gov");	
	Combobox2=lookup_widget(object,"addpolling_mun");
	Combobox3=lookup_widget(object,"addpolling_id");

	p.id=generate_id();

	p.cov_adps=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Cap));

	if(strcmp("Bizerte",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
		strcpy(p.gouv_addps,"Bizerte");
	else if(strcmp("Tunis",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
		strcpy(p.gouv_addps,"Tunis");
	else if(strcmp("Ariana",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
		strcpy(p.gouv_addps,"Ariana");
	else
		strcpy(p.gouv_addps,"Ben_Arous");
	if(strcmp("Raoued",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)))==0)
		strcpy(p.mun_addps,"Raoued");
	else if(strcmp("Ariana",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)))==0)
		strcpy(p.mun_addps,"Ariana");
	else if(strcmp("La_Soukra",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)))==0)
		strcpy(p.mun_addps,"La_Soukra");
	else
		strcpy(p.mun_addps," Mnihla");

	
	strcpy(p.idta_addps,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
	if (confirmradio=1)
	{
	add_pst("pstfile.txt",p);
	}
	else
	gtk_label_set_text(GTK_LABEL(output),"Please confirm you choices");

	GtkWidget *affichage;
	GtkWidget *w1;
	w1=lookup_widget(object,"Add_polling_station");
	affichage= create_Administator ();
	gtk_widget_show(affichage);
	gtk_widget_hide(w1);
}

void
on_modpolling_conf_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

void
on_modpolling_sub_clicked              (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *affichage;
	GtkWidget *w1;
	w1=lookup_widget(object,"Modify_polling_station");
	affichage= create_Administator ();
	gtk_widget_show(affichage);
	gtk_widget_hide(w1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_vote_add_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_vote_vote_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_claim_confirm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}




