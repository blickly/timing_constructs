void main() {
    tryin(300000000000 /* 5 minutes */; 30000000000 /* 30 seconds */) {
        for (;;) {
            beat_eggs();
        }
    } catch {
    put_eggs_in_pan();
    }
    remove_eggs_from_pan();
}
