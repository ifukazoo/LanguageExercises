use std::env;
use std::fs::File;
use std::io;
use std::io::BufRead;

fn main() {
    let args: Vec<String> = env::args().collect();
    let lines = if args.len() == 1 {
        let mut reader = io::BufReader::new(io::stdin());
        read_lines(&mut reader)
    } else {
        match File::open(&args[1]) {
            Ok(f) => {
                let mut reader = io::BufReader::new(f);
                read_lines(&mut reader)
            }
            Err(e) => Err(e),
        }
    };
    match lines {
        Ok(lines) => print_lines(&lines),
        Err(e) => eprintln!("{}", e),
    }
}

fn print_lines(buf: &Vec<String>) {
    for l in buf {
        let v: Vec<&str> = l.split(',').collect();
        let mut c = "";
        for w in v {
            print!("{}{}", c, w);
            c = " "
        }
        println!("")
    }
}

fn read_lines(buf: &mut dyn BufRead) -> io::Result<Vec<String>> {
    let mut lines: Vec<String> = vec![];
    loop {
        let mut text = String::new();
        if buf.read_line(&mut text)? == 0 {
            break;
        }
        lines.push(text.trim_end().to_string());
    }
    Ok(lines)
}
