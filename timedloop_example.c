void main() {
    timedloop(86400000000000 /* 24 hours */; 3600000000000 /* 1 hour */) {
        run_cron_job();
    } catch {
    log("Error: cron job executed for over an hour and was terminated");
    }
}
