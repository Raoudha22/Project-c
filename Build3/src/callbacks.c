#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Functionpst.h"


/*void
on_login_sign_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

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
*/

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
        f = fopen("pstfile.txt", "w");
        if (f != NULL)
        {
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id_pst, 1, &capacity, 2, &gouvernorate, 3, &municipality, 4, &id_agent, -1);
	    strcpy(p.id_pst,id);
	    strcpy(p.cov_adps,id);
	    strcpy(p.gouv_addps,id);
	    strcpy(p.mun_addps,id);
	    strcpy(p.idta_addps,id);
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

/*
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
*/

void
on_addpolling_conf_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_addpolling_sub_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modpolling_sub_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}

/*
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
*/
