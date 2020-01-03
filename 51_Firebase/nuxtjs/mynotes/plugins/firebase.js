import firebase from 'firebase/app'
import 'firebase/firestore'

if (!firebase.apps.length) {
    firebase.initializeApp({ projectId: process.env.FIREBASE_PROJECT_ID })
}
export default firebase