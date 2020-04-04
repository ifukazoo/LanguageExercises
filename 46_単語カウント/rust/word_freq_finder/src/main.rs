use std::collections::HashMap;
use std::env;
use std::fs::File;
use std::io;
use std::io::BufRead;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("Usage: {} <input file name>", args[0]);
        process::exit(1);
    }
    let map = count_word_freq(&args[1]);
    if let Err(e) = map {
        eprintln!("{}", e);
        process::exit(1);
    }
    let map = map.unwrap();
    let field_len = get_max_word_len(&map) as i32;
    print_map(&map, field_len);
}

fn count_word_freq(path: &str) -> io::Result<HashMap<String, i32>> {
    let mut map = HashMap::new();
    let f = File::open(&path)?;
    let mut reader = io::BufReader::new(f);
    loop {
        let mut line = String::new();
        if reader.read_line(&mut line)? == 0 {
            break;
        }
        for word in line.split_whitespace() {
            let word = word.trim_matches(|c: char| c.is_ascii_punctuation());
            let count = map.entry(word.to_string()).or_insert(0);
            *count += 1;
        }
    }
    Ok(map)
}

fn print_map(map: &HashMap<String, i32>, field: i32) {
    for (k, v) in map {
        // フォーマット文字列自体をフォーマットする方法が不明だった.
        println!("{:20}:{}", k, v);
    }
}

fn get_max_word_len<V>(map: &HashMap<String, V>) -> usize {
    map.keys()
        .max_by(|a, b| a.len().cmp(&b.len()))
        .unwrap_or(&String::new())
        .len()
}
