using System;
using System.ComponentModel;
using FlickrSearch.Helper;
using Xamarin.Forms;

namespace FlickrSearch.ViewModel
{
    /// <summary>
    /// Main view model.
    /// 未使用
    /// </summary>
    public class MainViewModel : BindableBase
    {
        private string tag;
        public string Tag
        {
            get
            {
                return tag;
            }
            set
            {
                SetProperty(ref tag, value);
            }
        }
    }
}
