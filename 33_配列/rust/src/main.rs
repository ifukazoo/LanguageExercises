extern crate rand;

use rand::{thread_rng, Rng};
use std::io::prelude::*;

fn main() -> std::io::Result<()> {
    print!("What's your question? ");
    std::io::stdout().flush()?;

    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf)?;

    let answers = vec!["Yes", "No", "Maybe", "Ask again later"];

    let num = thread_rng().gen_range(0, answers.len());
    // println!("{}", answers[num]);
    let answer = answers[num];
    println!("{}", answer);

    Ok(())
}
