using System;
using System.Net.Http;
using System.Runtime.Serialization.Json;
using System.Threading.Tasks;

namespace com.github.yamanobori_old {
    public static class Http {
        public static async Task<JSON> Get<JSON> (Uri uri) {
            var hc = new HttpClient ();
            var stream = await hc.GetStreamAsync (uri);
            var serializer = new DataContractJsonSerializer (typeof (JSON));
            return (JSON) serializer.ReadObject (stream);
        }
    }
}