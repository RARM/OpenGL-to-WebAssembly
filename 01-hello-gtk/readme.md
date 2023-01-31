# 01 Hello GTK
The objective of this module is to create an 800x600 window and attach an OpenGL context to it. This tutorial doesn't teach how to use the GTK toolkit, but it is used only to create a window and an OpenGL context. Eventually, the target platform will be WebAssembly and an HTML canvas instead of using a GTK toolkit.

## Installing and Testing GTK
Let's start by installing the appropriate tools. Use the [instructions for your platform](https://www.gtk.org/docs/installations/). For Ubuntu use:
```txt
$ apt update && apt install libgtk-4-dev
```

To start, follow the GTK tutorial for the [basics](https://docs.gtk.org/gtk4/getting_started.html#basics). Use the given code to create a blank window.

```c
#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
```

This code should create a 200x200 window. To change the dimensions, alter the `gtk_window_set_default_size()` function argument values to 800 and 600. Add the `gtk_window_set_resizable()` function if you want to disable resizing.

## The OpenGL Context

```txt
gcc $(pkg-config --cflags gtk4) -o main.out main.c -Wall $(pkg-config --libs gtk4) -lGL
```

Or `-lepoxy`.