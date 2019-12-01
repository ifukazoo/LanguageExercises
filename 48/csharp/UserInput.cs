using System;

namespace com.github.yamanobori_old {
    public static class UserInput {

        private static string Read (string prompt) {
            Console.Write (prompt);
            return Console.ReadLine ();
        }
        public static T ReadWithValidator<T> (string prompt, Func<string, T> validator, string invalMsg) {
            retry : var input = Read (prompt);
            try {
                return validator (input);
            } catch (FormatException) {
                Console.WriteLine (invalMsg);
                goto retry;
            }
        }
    }
}