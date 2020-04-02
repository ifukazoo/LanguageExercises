use std::fs;
use std::io;
use std::io::Write;
use std::process;

fn main() {
    let mut names: Vec<String> = vec![];
    loop {
        let mut line = String::new();
        match std::io::stdin().read_line(&mut line) {
            Ok(0) => break,
            Ok(_) => names.push(String::from(line.trim_end())),
            Err(e) => {
                eprintln!("{}", e);
                process::exit(1);
            }
        }
    }
    names.sort();
    let names = names.join("\n") + "\n";
    write_file("result", &names).unwrap_or_else(|err| {
        eprintln!("{}", err);
        process::exit(1);
    });
}

fn write_file(path: &str, content: &str) -> io::Result<()> {
    let mut f = fs::File::create(path)?;
    let mut pos = 0;
    while pos < content.len() {
        let b = content.as_bytes();
        let written = f.write(&b)?;
        pos += written;
    }
    Ok(())
}
