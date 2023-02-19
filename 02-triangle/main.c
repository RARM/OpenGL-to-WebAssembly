// Creating a blank window.
#include <gtk/gtk.h>
#include <GL/gl.h>

static gboolean render(GtkGLArea *area, GdkGLContext *context) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background black.
    glClear(GL_COLOR_BUFFER_BIT);

    // OpenGL code here...

    return 1;
}

static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget* window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello OpenGL");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_resizable(GTK_WINDOW(window), 0);
    // gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    
    // Adding an OpenGL context.
    GtkWidget* gl_area = gtk_gl_area_new();
    g_signal_connect(gl_area, "render", G_CALLBACK(render), NULL);
    gtk_window_set_child(GTK_WINDOW(window), gl_area);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);    
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}