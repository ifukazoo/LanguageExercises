using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Threading.Tasks;
using FlickrSearch.Model;
using FlickrSearch.ViewModel;
using Xamarin.Forms;

namespace FlickrSearch
{
    // Learn more about making custom code visible in the Xamarin.Forms previewer
    // by visiting https://aka.ms/xamarinforms-previewer
    [DesignTimeVisible(false)]
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        async void OnClickedSearch(object sender, EventArgs e)
        {
            Flickr.Feed feed = await Flickr.DownloadFeed(Tags.Text);
            var list = new List<Flickr.Item>();
            foreach (var item in feed.items)
            {
                list.Add(item);
            }
            listView.ItemsSource = list;
        }

        void Handle_ItemSelected(object sender, Xamarin.Forms.SelectedItemChangedEventArgs e)
        {
            var item = e.SelectedItem as Flickr.Item;
            Application.Current.MainPage.Navigation.PushAsync(new DetailPage(item));
        }
    }
}
