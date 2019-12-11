using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using static FlickrSearch.Model.Flickr;

namespace FlickrSearch
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class DetailPage : ContentPage
    {
        public DetailPage(Item item)
        {
            InitializeComponent();
            image.Source = ImageSource.FromUri(new Uri(item.media.m));
            var d = new Dictionary<string, string>();
            d.Add("タイトル", item.title);
            d.Add("作者", item.author);
            d.Add("作者 ID", item.author_id);
            d.Add("撮影日", item.date_taken.ToString("yyyy-MM-dd HH:MM:SS"));
            d.Add("発行日", item.published.ToString("yyyy-MM-dd HH:MM:SS"));
            d.Add("説明", item.description);
            d.Add("タグ", item.tags);
            details.ItemsSource = d;
        }
    }
}
