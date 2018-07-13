int main() {
    Window window;
    window.create("Test", 640, 480);
    Renderer renderer{window};
    TextureLoader textureLoader(renderer);
    Texture cat = textureLoader.load("cat.png");
    Transform catTransform; // translate, scale, rotate

    bool running = true;
    while (running) {
        Event e;
        while (window.pollEvent(e))
            if (e.type == Event::Closed) {
                running = false;
            }
        }

        renderer.clear({0, 0, 0});
        renderer.render(texture, catTransform);
        renderer.present();
    }

    return 0;
}
