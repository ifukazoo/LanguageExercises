var app = new Vue({
  el: '#app',
  data: {
    input: ''
  },
  computed: {
    inputlen: function () {
      return this.input.length
    }
  }
})
