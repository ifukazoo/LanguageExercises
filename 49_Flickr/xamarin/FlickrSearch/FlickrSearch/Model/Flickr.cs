using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Xamarin.Forms;
using static FlickrSearch.Model.Flickr;

namespace FlickrSearch.Model
{
    public class Flickr
    {
        [DataContract]
        public class Media
        {
            [DataMember]
            public string m { get; set; }
        }

        [DataContract]
        public class Item
        {
            [DataMember]
            public string title { get; set; }
            [DataMember]
            public string link { get; set; }
            [DataMember]
            public Media media { get; set; }
            [DataMember]
            public DateTime date_taken { get; set; }
            [DataMember]
            public string description { get; set; }
            [DataMember]
            public DateTime published { get; set; }
            [DataMember]
            public string author { get; set; }
            [DataMember]
            public string author_id { get; set; }
            [DataMember]
            public string tags { get; set; }
        }

        [DataContract]
        public class Feed
        {
            [DataMember]
            public string title { get; set; }
            [DataMember]
            public string link { get; set; }
            [DataMember]
            public string description { get; set; }
            [DataMember]
            public DateTime modified { get; set; }
            [DataMember]
            public string generator { get; set; }
            [DataMember]
            public List<Item> items { get; set; }
        }

        public static async Task<Feed> DownloadFeed(string tags)
        {
            var url = new Uri($"https://www.flickr.com/services/feeds/photos_public.gne?format=json&tags={tags}");
            var http = new HttpClient();
            var res = await http.GetAsync(url);
            var json = await res.Content.ReadAsStringAsync();
            var head = new Regex(@"\AjsonFlickrFeed\(");
            json = head.Replace(json, "");
            var tail = new Regex(@"\)\z");
            json = tail.Replace(json, "");
            return JsonConvert.DeserializeObject<Feed>(json);
        }
    }
}
