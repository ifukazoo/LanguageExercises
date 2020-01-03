import firebase from '~/plugins/firebase'
import { vuexfireMutations, firestoreAction } from 'vuexfire'
import lodash from "lodash"

const notesRef = firebase.firestore().collection('notes')

const state = function () {
    return {
        lists: [],
    }
}

export const getters = {
    notes: function (state) {
        return lodash.sortBy(state.lists, "created").map(note => {
            return {
                text: note.text,
                created: new Date(note.created / 1000 / 1000)
            }
        })
    }
}
export const mutations = {
    ...vuexfireMutations,
}

export const actions = {
    init: firestoreAction(({ bindFirestoreRef }) =>
        // return the promise returned by `bindFirestoreRef`
        bindFirestoreRef('lists', notesRef)
    ),
    add: firestoreAction(function (context, text) {
        if (text.trim()) {
            notesRef.add(
                {
                    text: text,
                    created: Date.now() * 1000 * 1000
                }
            )
        }
    })
}
