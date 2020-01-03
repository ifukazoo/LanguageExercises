<template>
  <div class="container">
    <div>
      <h2>My notes</h2>
      <br />
    </div>
    <ul style="font-family:monospace; list-style-type:none">
      <li
        v-for="note in notes"
        v-bind:key="note.created.value"
      >{{note.created | dateFilter}} {{note.text}}</li>
    </ul>
    <input style="margin-left: 4%" v-model="text" />
    <button v-on:click="addNotes">new</button>
  </div>
</template>

<script>
import moment from "moment";
export default {
  data: function() {
    return {
      text: ""
    };
  },
  created: function() {
    this.$store.dispatch("notes/init");
  },
  computed: {
    notes() {
      // getters.notes などとしたかったが
      // gettersはこの形でしか参照できない.
      return this.$store.getters["notes/notes"];
    }
  },
  filters: {
    // momentライブラリをimportした
    dateFilter: function(date) {
      return moment(date).format("YYYY-MM-DD");
    }
  },
  methods: {
    addNotes() {
      this.$store.dispatch("notes/add", this.text);
      this.text = "";
    }
  }
};
</script>

<style>
</style>
