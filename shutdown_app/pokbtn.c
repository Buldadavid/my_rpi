#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

static void
fce1(GtkWidget *widget, gpointer   data) {
   system ("/usr/bin/pkill orca;/sbin/shutdown -h now");
}

static void
fce2(GtkWidget *widget, gpointer   data) {
   system ("/usr/bin/pkill orca;/sbin/reboot");
}

static void
fce3(GtkWidget *widget, gpointer   data) {
   system ("/bin/kill $_LXSESSION_PID");
}

void destroy(GtkWidget* widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char* argv[])
{

    gtk_init(&argc, &argv);
    GtkWidget *win, *label, *btn,*btn2,*btn3, *vbox;

     win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_widget_set_size_request(win, 300, 120);
     gtk_window_set_resizable(GTK_WINDOW (win), FALSE);
     gtk_window_set_title (GTK_WINDOW (win), "Shutdown options");
     gtk_container_set_border_width (GTK_CONTAINER (win), 10);
     gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);

    g_signal_connect(win, "destroy",
                    G_CALLBACK(destroy), NULL);
                    
     btn = gtk_button_new_with_label("Shutdown"); 
     g_signal_connect (btn, "clicked", G_CALLBACK (fce1), NULL);
     btn2 = gtk_button_new_with_label("Reboot");
     g_signal_connect (btn2, "clicked", G_CALLBACK (fce2), NULL);
     btn3 = gtk_button_new_with_label("Logout");
     g_signal_connect (btn3, "clicked", G_CALLBACK (fce3), NULL);

     vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,5); 
     gtk_box_pack_start(GTK_BOX(vbox),btn,0,0,0); 
     gtk_box_pack_start(GTK_BOX(vbox),btn2,0,0,0);
     gtk_box_pack_start(GTK_BOX(vbox),btn3,0,0,0);

     gtk_container_add(GTK_CONTAINER(win),vbox); 

     gtk_widget_show_all(win);                     
                    
    gtk_main();

    return 0;
}

