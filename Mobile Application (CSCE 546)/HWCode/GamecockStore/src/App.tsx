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
import { IonReactRouter } from "@ionic/react-router";
import { apps, flash, send } from "ionicons/icons";
import ProductListPage from "./pages/ProductPages/ProductListPage";
import AddProductPage from "./pages/ProductPages/AddProductPage";
import ProductDetailPage from "./pages/ProductPages/ProductDetailPage";
import OrderListPage from "./pages/OrderPages/OrderListPage";
import OrderDetailPage from "./pages/OrderPages/OrderDetailPage";
import {
  Redirect,
  BrowserRouter as Router,
  Route,
  Link
} from "react-router-dom";
 
import Details from "./pages/Details";

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

export default class App extends React.Component {
  constructor(props: any) {
    super(props);
  }
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
                path="/"
                render={() => <Redirect to="/ProductListPage" />}
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
