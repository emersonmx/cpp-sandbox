int main() {
    Window window;
    window.create("Test", 640, 480);
    Renderer renderer{window};

    bool running = true;
    while (running) {
        Event e;
        while (window.pollEvent(e))
            if (e.type == Event::Closed) {
                running = false;
            }
        }

        renderer.clear({0, 0, 0});
        renderer.render(texture, {100, 100}, transform);
        renderer.present();
    }

    return 0;
}
