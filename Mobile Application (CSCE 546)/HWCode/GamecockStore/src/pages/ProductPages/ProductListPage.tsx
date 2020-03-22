import {
  IonCard,
  IonCardHeader,
  IonCardSubtitle,
  IonCardTitle,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonText,
  IonButton
} from "@ionic/react";
import { connect } from "react-redux";
import { Link } from "react-router-dom";
import React, { Component } from "react";
import firebase from "firebase";
import { toast } from "../../components/toast";
import { checkCurrentUser, handleSignOut, toggleStoreOwner, testWatch } from "../../App";
import { watchProducts } from "../../redux/react-redux";
import { returnUserUID } from "../../App";
import { withRouter } from "react-router";

const mapStateToProps = (state: any) => {
  return {
    products: state.productsF
  };
};

const mapDispatchToProps = (dispatch: any) => {
  return {
    watchProducts: () => {
      dispatch(watchProducts());
    }
  };
};

export interface IAppProps {
  history: any;
  location: any;
  match: any;
  products: [];
  watchProducts: any;
}

export interface IAppState {
  currentUser: any;
}

class ProductListPage extends React.Component<IAppProps, IAppState> {
  constructor(props: IAppProps) {
    checkCurrentUser().then((user: any) => {
      if (user !== null) {
        this.setState({ currentUser: user });
        toast(this.state.currentUser.uid);
      } else {
        console.log("CURRENT USER IS NULL");
      }
    });
    super(props);
    this.props.watchProducts();
  }

  componentWillUnmount() {}

  async _loginOrLogout() {
    await handleSignOut();
    this.props.history.replace("/Login", null);
  }

  _createCardList(products: []) {
    return products.map((product: any) => {
      return (
        <Link
          to={{
            pathname: "/ProductListPage/ProductDetailPage",
            state: { product: product }
          }}
          style={{ textDecoration: "none" }}
        >
          <IonCard className="card" key={product.pID}>
            <IonCardHeader>
              <IonCardTitle>{product.name}</IonCardTitle>
              <IonCardSubtitle>
                <IonText>Price: $</IonText>
                {product.price}
              </IonCardSubtitle>
              <IonCardSubtitle>{product.category} </IonCardSubtitle>
            </IonCardHeader>
            <img src={product.imgURL} />
            <IonText>Description: {product.description}</IonText>
          </IonCard>
        </Link>
      );
    });
  }

  public render() {
    let productCards: any = this._createCardList(this.props.products);
    //console.log(productCards);
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Products</IonTitle>
            <IonButton
              onClick={() => handleSignOut()}
              slot="start"
              routerDirection="back"
              routerLink="/Login"
            >
              Log Out
            </IonButton>
            <IonButton
              onClick={() => handleSignOut()}
              slot="start"
              routerLink="/Login"
              routerDirection="back"
            >
              Log In
            </IonButton>
            <IonButton slot="end" routerLink="/ProductListPage/AddProductPage">
              <IonText>Add Product</IonText>
            </IonButton>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonButton
            routerDirection="forward"
            routerLink="/ProductListPage/ShoppingCart"
          >
            Shopping Cart
          </IonButton>
          {productCards}
          <IonButton onClick={() => toggleStoreOwner()}>
            Toggle StoreOwner
          </IonButton>
        </IonContent>
      </IonPage>
    );
  }
}

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(withRouter(ProductListPage));
