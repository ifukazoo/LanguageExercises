using System;
using System.Linq;
using System.Net.Http;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Threading.Tasks;

namespace csharp {

    [DataContract]
    class Astronaut {
        [DataMember (Name = "name")]
        internal string Name;
        [DataMember (Name = "craft")]
        internal string Craft;
    }

    [DataContract]
    class Astros {
        [DataMember (Name = "people")]
        internal Astronaut[] People;
        [DataMember (Name = "number")]
        internal int Number;
        [DataMember (Name = "message")]
        internal string Message;
    }

    class Program {

        private static async Task<Astros> GetAstrosAsync () {
            var hc = new HttpClient ();
            var stream = await hc.GetStreamAsync ("http://api.open-notify.org/astros.json");
            var serializer = new DataContractJsonSerializer (typeof (Astros));
            return serializer.ReadObject (stream) as Astros;
        }

        private static void DispLine (string left, int leftLen, string right, int rightLen) {
            var lfmt = "{0," + $"-{leftLen}" + "}";
            var rfmt = "{1:" + $"-{rightLen}" + "}";
            Console.WriteLine (string.Format (lfmt + "|" + rfmt, left, right));
        }

        private static void DispSeparator (int leftLen, int rightLen) {
            var lsep = "";
            for (var i = 0; i < leftLen; i++) {
                lsep += "-";
            }
            var rsep = "";
            for (var i = 0; i < rightLen; i++) {
                rsep += "-";
            }
            DispLine (lsep, leftLen, rsep, rightLen);
        }

        private static void DispAstros (Astronaut[] astros) {
            var nameFieldLen = astros.Max (a => a.Name.Length) + 1;
            DispLine ("Name", nameFieldLen, " Craft", 6);
            DispSeparator(nameFieldLen, 6);
            foreach (var astro in astros) {
                DispLine (astro.Name, nameFieldLen, " " + astro.Craft, 6);
            }
        }

        static void Main (string[] args) {
            var astros = GetAstrosAsync ().Result;
            if (astros.Message == "success") {
                DispAstros (astros.People);
            }
        }
    }
}

