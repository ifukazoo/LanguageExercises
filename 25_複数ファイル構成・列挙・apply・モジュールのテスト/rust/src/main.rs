mod validator;

// cargo で作成した単位がcrateである.

fn output(password: &str) {
    let strength = validator::validate_password(password);
    println!("The password '{}' is a {} password.", password, strength);
}

fn main() {
    output("12345");
    output("abcdef");
    output("abc123xyz");
    output("1337h@xor!");
}
