use std::collections::HashMap;
use std::io;
use std::io::Write;

fn main() {
    let mut password_data = HashMap::new();
    password_data.insert(String::from("figaro"), String::from("abcd"));
    password_data.insert(String::from("susanna"), String::from("1234"));
    password_data.insert(String::from("almaviva"), String::from("ABCD"));
    password_data.insert(String::from("rosina"), String::from("5678"));

    print!("What is the usernames? ");
    io::stdout().flush().unwrap();

    let mut input_name = String::new();
    io::stdin().read_line(&mut input_name).unwrap();
    let input_name = input_name.trim();

    print!("What is the password? ");
    io::stdout().flush().unwrap();

    let mut input_password = String::new();
    io::stdin().read_line(&mut input_password).unwrap();
    let input_password = input_password.trim();

    let password = password_data.get(input_name);
    match password {
        Some(o) => {
            if o == input_password {
                println!("Welcome!");
            } else {
                println!("I don't know you.");
            }
        }
        _ => println!("I don't know you."),
    }
}
