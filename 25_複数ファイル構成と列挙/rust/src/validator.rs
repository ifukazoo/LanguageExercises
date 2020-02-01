#[derive(Debug, PartialEq)]
pub enum Strength {
    // VeryWeak 最弱
    VeryWeak,
    // Weak 弱
    Weak,
    // Normal ふつう
    Normal,
    // Strong 強
    Strong,
    // VeryStrong 最強
    VeryStrong,
}

impl std::fmt::Display for Strength {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        match *self {
            Strength::VeryWeak => write!(f, "very weak"),
            Strength::Weak => write!(f, "weak"),
            Strength::Normal => write!(f, "normal"),
            Strength::Strong => write!(f, "strong"),
            Strength::VeryStrong => write!(f, "very strong"),
        }
    }
}

pub fn validate_password(password: &str) -> Strength {
    let length_min = 8;
    let number_only = password.chars().all(|c| c.is_numeric());
    let letter_only = password.chars().all(|c| c.is_alphabetic());
    let contains_special = password.chars().any(|c| c.is_ascii_punctuation());
    let contains_letter = password.chars().any(|c| c.is_alphabetic());
    let contains_number = password.chars().any(|c| c.is_numeric());
    let too_short = password.len() < length_min;

    if too_short {
        if number_only {
            return Strength::VeryWeak;
        }
        if letter_only {
            return Strength::Weak;
        }
    } else {
        if contains_letter && contains_number && contains_special {
            return Strength::VeryStrong;
        }
        if contains_letter && contains_number {
            return Strength::Strong;
        }
    }
    Strength::Normal
}

#[test]
fn test_password_validator() {
    assert_eq!(validate_password(""), Strength::VeryWeak);
    assert_eq!(validate_password("1234567"), Strength::VeryWeak);
    assert_eq!(validate_password("aaaaaaa"), Strength::Weak);
    assert_eq!(validate_password("aaaaaa@"), Strength::Normal);
    assert_eq!(validate_password("123456@"), Strength::Normal);
    assert_eq!(validate_password("aaaaaaaa"), Strength::Normal);
    assert_eq!(validate_password("12345678"), Strength::Normal);
    assert_eq!(validate_password("########"), Strength::Normal);
    assert_eq!(validate_password("aaaaaaa8"), Strength::Strong);
    assert_eq!(validate_password("1234567a"), Strength::Strong);
    assert_eq!(validate_password("aaaaaa#8"), Strength::VeryStrong);
    assert_eq!(validate_password("123456#a"), Strength::VeryStrong);
}
