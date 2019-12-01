package validator

import (
	"unicode"
)

// Strength 強さ
type Strength int

const (
	// VeryWeak 最弱
	VeryWeak Strength = iota
	// Weak 弱
	Weak
	// Normal ふつう
	Normal
	// Strong 強
	Strong
	// VeryStrong 最強
	VeryStrong
)

func (o Strength) String() string {
	switch o {
	case VeryWeak:
		return "very weak"
	case Weak:
		return "weak"
	case Normal:
		return "normal"
	case Strong:
		return "strong"
	case VeryStrong:
		return "very strong"
	default:
		break
	}
	panic("must not reach.")
}

func isAlpha(r rune) bool {
	if ('a' <= r && r <= 'z') || ('A' <= r && r <= 'Z') {
		return true
	}
	return false
}

const passwordLenghtMin = 8

// PasswordValidator パスワード強度
func PasswordValidator(password string) Strength {
	numberOnly := allOf(password, unicode.IsDigit)
	letterOnly := allOf(password, isAlpha)
	containsSpecial := anyOf(password, unicode.IsPunct)
	containsLetter := anyOf(password, isAlpha)
	containsNumber := anyOf(password, unicode.IsDigit)
	tooShort := len(password) < passwordLenghtMin

	if tooShort {
		if numberOnly {
			return VeryWeak
		} else if letterOnly {
			return Weak
		}
	} else {
		if containsLetter && containsNumber && containsSpecial {
			return VeryStrong
		}
		if containsLetter && containsNumber {
			return Strong
		}
	}
	return Normal
}
func allOf(s string, f func(rune) bool) bool {
	for _, r := range s {
		if !f(r) {
			return false
		}
	}
	return true
}
func anyOf(s string, f func(rune) bool) bool {
	for _, r := range s {
		if f(r) {
			return true
		}
	}
	return false
}
