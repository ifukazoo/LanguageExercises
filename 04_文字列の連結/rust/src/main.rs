use std::io;
use std::io::Write;

fn main() -> Result<(), std::io::Error> {
    let mut noun = String::new();
    print!("Enter a noun: ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut noun)?;
    let noun = noun.trim();

    let mut verb = String::new();
    print!("Enter a verv: ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut verb)?;
    let verb = verb.trim();

    let mut adjective = String::new();
    print!("Enter an adjective: ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut adjective)?;
    let adjective = adjective.trim();

    let mut adverb = String::new();
    print!("Enter an adverb: ");
    io::stdout().flush()?;
    io::stdin().read_line(&mut adverb)?;
    let adverb = adverb.trim();

    let s = format!(
        "Do you {} your {} {} {}? That's hilarious!",
        verb, adjective, noun, adverb
    );

    println!("{}", s);

    Ok(())
}
