using System;

namespace com.github.yamanobori_old {
    class Program {

        static Func<string, string> validateNotEmpty = (s) => {
            if (string.IsNullOrWhiteSpace (s)) {
                new FormatException ();
            }
            return s;
        };

        static void Main (string[] args) {

            var invalMsg = "Sorry. That's not a valid input.";

            var appid = UserInput.ReadWithValidator (
                prompt: "What is your openweather api appid? :",
                validator : validateNotEmpty,
                invalMsg : invalMsg);

            var city = UserInput.ReadWithValidator (
                prompt: "Where are you? :",
                validator : validateNotEmpty,
                invalMsg : invalMsg);
            try {
                var result = Http.Get<Rootobject> (new Uri ($"http://api.openweathermap.org/data/2.5/weather?q={city}&APPID={appid}&units=metric")).Result;
                if (result.cod == 200) {
                    Console.WriteLine ($"{city} weather: {result.weather[0].main}");
                    Console.WriteLine ($"{result.main.temp} degrees Celsius");
                }
            } catch (AggregateException e) {
                foreach (var err in e.InnerExceptions) {
                    Console.WriteLine ($"error:{e.Message}");
                }
            }
        }
    }
}