use std::io;
use std::io::Write;

fn is_anagram(a: &str, b: &str) -> bool {
    if a.len() != b.len() {
        return false;
    }
    for c in a.chars() {
        if !b.contains(c) {
            return false;
        }
    }
    true
}

fn main() -> Result<(), std::io::Error> {
    print!("Enter two strings and I'll tell you if then are anagrams: ");
    io::stdout().flush()?;

    let mut first = String::new();
    io::stdin().read_line(&mut first)?;
    let first = first.trim();

    print!("Enter the second string: ");
    io::stdout().flush()?;

    let mut second = String::new();
    io::stdin().read_line(&mut second)?;
    let second = second.trim();

    let ok = is_anagram(first, second);

    let mut not = "";
    if !ok {
        not = "not "
    }
    println!(r#"{} and {} are {}anagrams."#, first, second, not);

    Ok(())
}
