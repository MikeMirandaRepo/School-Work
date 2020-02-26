import React, { Component } from "react";
import {
  IonApp,
  IonIcon,
  IonLabel,
  IonRouterOutlet,
  IonTabBar,
  IonTabButton,
  IonTabs
} from "@ionic/react";
import firebase from "firebase";
import { IonReactRouter } from "@ionic/react-router";
import { apps, flash, send } from "ionicons/icons";
import ProductListPage from "./pages/ProductPages/ProductListPage";
import AddProductPage from "./pages/ProductPages/AddProductPage";
import ProductDetailPage from "./pages/ProductPages/ProductDetailPage";
import OrderListPage from "./pages/OrderPages/OrderListPage";
import OrderDetailPage from "./pages/OrderPages/OrderDetailPage";
import Login from "./pages/Auth/Login";
import SignUp from "./pages/Auth/SignUp";

import {
  Redirect,
  BrowserRouter as Router,
  Route,
  Link
} from "react-router-dom";
/* Core CSS required for Ionic components to work properly */
import "@ionic/react/css/core.css";

/* Basic CSS for apps built with Ionic */
import "@ionic/react/css/normalize.css";
import "@ionic/react/css/structure.css";
import "@ionic/react/css/typography.css";

/* Optional CSS utils that can be commented out */
import "@ionic/react/css/padding.css";
import "@ionic/react/css/float-elements.css";
import "@ionic/react/css/text-alignment.css";
import "@ionic/react/css/text-transformation.css";
import "@ionic/react/css/flex-utils.css";
import "@ionic/react/css/display.css";

/* Theme variables */
import "./theme/variables.css";
import { render } from "@testing-library/react";
import { resolve } from "dns";
import { rejects } from "assert";
import { toast } from "./components/toast";

var firebaseConfig = {
  apiKey: "AIzaSyDRpqwzkbL7bljwjFB0jQ8iW9aozm9I21M",
  authDomain: "gamecockstore-37e56.firebaseapp.com",
  databaseURL: "https://gamecockstore-37e56.firebaseio.com",
  projectId: "gamecockstore-37e56",
  storageBucket: "gamecockstore-37e56.appspot.com",
  messagingSenderId: "1027386417640",
  appId: "1:1027386417640:web:bf85e82ea43549efb2c45d",
  measurementId: "G-VRK9TW2VBD"
};
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
firebase.analytics();
let db = firebase.firestore();
export { db };

export async function checkCurrentUser() {
  return new Promise((resolve, reject) => {
    var unsubscribe = firebase.auth().onAuthStateChanged(function(user) {
      user = firebase.auth().currentUser;
      if (user) {
        toast(user.uid);
        resolve(user);
      } else {
        toast("There is no user Logged In");
        reject(null);
      }
      unsubscribe();
    });
  });
}


export async function handleSignOut() {
  if (firebase.auth()) {
    await firebase.auth().signOut();
    toast("You have signed out");
  } else {
    toast("No logged in User");
  }
}

export default class App extends React.Component {
  render() {
    return (
      <IonApp>
        <IonReactRouter>
          <IonTabs>
            <IonRouterOutlet>
              <Link to="/OrderListPage" />
              <Route
                path="/OrderListPage"
                component={OrderListPage}
                exact={true}
              />
              <Route path="/OrderListPage/details" component={OrderListPage} />
              <Route
                path=""
                render={() => <Redirect to="/Login" />}
                exact={true}
              />
              <Route
                path="/ProductListPage"
                component={ProductListPage}
                exact={true}
              />
              <Route
                path="/ProductListPage/AddProductPage"
                component={AddProductPage}
                exact={true}
              />
              <Route
                path="/ProductListPage/ProductDetailPage"
                component={ProductDetailPage}
                exact={true}
              />
              <Route
                path="/OrderDetailList/OrderDetailPage"
                component={OrderDetailPage}
                exact={true}
              />
              <Route
                path="/ProductDetailPage"
                component={ProductDetailPage}
                exact
              />
              <Route path="/Login" component={Login} />
              <Route path="/SignUp" component={SignUp} />
            </IonRouterOutlet>
            <IonTabBar slot="bottom">
              <IonTabButton tab="ProductListPage" href="/ProductListPage">
                <IonIcon icon={flash} />
                <IonLabel>Product List</IonLabel>
              </IonTabButton>
              <IonTabButton tab="OrderListPage" href="/OrderListPage">
                <IonIcon icon={apps} />
                <IonLabel>Order List</IonLabel>
              </IonTabButton>
            </IonTabBar>
          </IonTabs>
        </IonReactRouter>
      </IonApp>
    );
  }
}
