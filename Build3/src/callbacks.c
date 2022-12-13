#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Functionpst1.h"


void
on_login_sign_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *affichage;
	GtkWidget *treeview;
	affichage= create_Administator ();
	gtk_widget_show(affichage);
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
    
    GtkTreeModel *model = gtk_tree_view_get_model("list_polling");
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        FILE *f;
        f = fopen("pstfile.txt", "w");
        if (f != NULL)
        {
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id_pst, 1, &capacity, 2, &gouvernorate, 3, &municipality, 4, &id_agent, -1);
	    p.id=id_pst;
	    strcpy(p.cov_adps,capacity);
	    strcpy(p.gouv_addps,gouvernorate);
	    strcpy(p.mun_addps,municipality);
	    strcpy(p.idta_addps,id_agent);
	    fclose(f);
        }
    }
}


void
on_polling_mod_clicked                 (GtkWidget      *object,
                                        gpointer         user_data)
{
 GtkWidget *mod;
    mod = create_Modify_polling_station();
    gtk_widget_show(mod);
}


void
on_polling_search_clicked              (GtkWidget       *object,
                                        gpointer         user_data)
{
    /*Polling_station p,p2;
    char filename[30] = "pstfile.txt", tab[20], msg[200] = "L'utilsateur a ete trouvé CIN:";
    GtkWidget *input_id;
    int id;
    input_id = lookup_widget(objet, "searchpolling");
    id=gtk_entry_get_text(GTK_ENTRY(input_id)));
    p2 = recherche("pstfile.txt", id);
    if(p2.id==-1)
    {
        FILE *f = fopen(filename, "r");
        if (f != NULL)
        {
            while (fscanf(f, "%s %s %s %s %s %s %s %s\n", p.nom, p.prenom, p.cin, p.sexe, p.jour, p.etat, p.bv, p.vote) == R)
            {
            }
            fclose(f);
        }
        strcat(debut, p.cin);
        strcat(debut, " NOM:");
        strcat(debut, p.nom);
        strcat(debut, " PRENOM:");
        strcat(debut, p.prenom);
        strcat(debut, " DATE DE NAISSANCE:");
        strcat(debut, p.jour);
        strcat(debut, " SEXE:");
        strcat(debut, p.sexe);
        strcat(debut, " Role:");
        strcat(debut, p.etat);
        strcat(debut, " BUREAU DE VOTE");
        strcat(debut, p.bv);
        strcat(debut, " Etat De VOTE");
        strcat(debut, p.vote);

        GtkWidget *output;
        output = lookup_widget(objet_graphique, "resultat_label");
        gtk_label_set_text(GTK_LABEL(output), debut);
        FILE *f2;
        f2 = fopen("selection.txt", "w");
        if (f2!= NULL)
        {
            fprintf(f2, "%s", p.cin);
            fclose(f2);
        }
    }
    else
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "resultat_label");
        gtk_label_set_text(GTK_LABEL(output), "Aucun Utilisateur n'a ete Trouvé");
    }*/
}


void
on_polling_add_clicked                 (GtkWidget       *object,
                                        gpointer         user_data)
{
    GtkWidget *add;
    add = create_Add_polling_station();
    gtk_widget_show(add);
}


void
on_polling_del_clicked                 (GtkWidget       *object,
                                        gpointer         user_data)
{

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


void
on_addpolling_conf_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_addpolling_sub_clicked              (GtkWidget       *object,
                                        gpointer         user_data)
{

}


void
on_modpolling_sub_clicked              (GtkWidget       *object,
                                        gpointer         user_data)
{

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

