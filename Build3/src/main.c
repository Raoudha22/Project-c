/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *Login;
  GtkWidget *Administator;
  GtkWidget *Add_user;
  GtkWidget *Modify_user_;
  GtkWidget *Add_election_managment;
  GtkWidget *Modify_election_managment;
  GtkWidget *Electral_list;
  GtkWidget *Add_polling_station;
  GtkWidget *Modify_polling_station;
  GtkWidget *Vote;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  Login = create_Login ();
  gtk_widget_show (Login);
  /*Administator = create_Administator ();
  gtk_widget_show (Administator);
  	Add_user = create_Add_user ();
  gtk_widget_show (Add_user);
  Modify_user_ = create_Modify_user_ ();
  gtk_widget_show (Modify_user_);
  Add_election_managment = create_Add_election_managment ();
  gtk_widget_show (Add_election_managment);
  Modify_election_managment = create_Modify_election_managment ();
  gtk_widget_show (Modify_election_managment);
  Electral_list = create_Electral_list ();
  gtk_widget_show (Electral_list);
  Add_polling_station = create_Add_polling_station ();
  gtk_widget_show (Add_polling_station);
  Modify_polling_station = create_Modify_polling_station ();
  gtk_widget_show (Modify_polling_station);
  Vote = create_Vote ();
  gtk_widget_show (Vote);*/

  gtk_main ();
  return 0;
}

