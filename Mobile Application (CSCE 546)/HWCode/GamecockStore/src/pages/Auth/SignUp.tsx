import {
  IonCard,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonButton,
  IonInput,
  IonList
} from "@ionic/react";
import { Link } from "react-router-dom";
import { withRouter } from "react-router";

import firebase from "firebase";
import React from "react";
import { db, returnUserUID } from "../../App";
import {
  defaultProducts,
  defaultOrders,
  defaultOrderIDs,
  defaultProductIDs
} from "../../redux/react-redux";
import { toast } from "../../components/toast";
import {
  googleSignIn,
 // signInGoogle1
} from "../../App";

export interface SignUpProps {
  history: any;
  location: any;
  match: any;
}

export interface SignUpState {
  email: "";
  password: "";
  storeOwner: null;
}

class SignUp extends React.Component<SignUpProps, SignUpState> {
  constructor(props: SignUpProps) {
    super(props);

    this.state = {
      email: "",
      password: "",
      storeOwner: null
    };
  }

  handleSignUp = async () => {
    try {
      const signUp = await firebase
        .auth()
        .createUserWithEmailAndPassword(this.state.email, this.state.password)
        .then(() => {
          let userData = {
            orders: [],
            storeOwner: true
            //products: defaultProductIDs
          };
          // Add user data to users collection with doc id of uid
          db.collection("users")
            .doc(returnUserUID())
            .set(userData)
            .then(() => {
              toast("Created a User");
            })
            .catch(error => {
              console.error("Google Sign In Failure", error);
              return false;
            });
          return true;
        });
    } catch (error) {
      console.log(error);
      return false;
    }
  };

  async _handleSignUp() {
    const res = await this.handleSignUp();
    if (res) {
      this.props.history.replace("/LoginPage", null);
    } else {
      console.log("Error Signing Up With Email!");
    }
  }

  async _loginWithGoogle() {
    await googleSignIn().then(res => {
      if (res) {
        this.props.history.replace("/ProductListPage", null);
      } else {
        console.log("Error Logging In With Google!");
        toast("Error Logging In With Google!");
      }
    });
  }

  public render() {
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>SignUp</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonCard>
            <IonList>
              <IonInput
                placeholder="Email"
                required={true}
                type="email"
                onIonChange={(e: any) =>
                  this.setState({ email: e.detail.value })
                }
              />
              <IonInput
                placeholder="Password"
                required={true}
                type="password"
                onIonChange={(e: any) =>
                  this.setState({ password: e.detail.value })
                }
              />
            </IonList>
            <IonButton
              routerDirection="back"
              onClick={() => this.handleSignUp()}
              routerLink="/Login"
            >
              Sign Up
            </IonButton>
            <IonButton onClick={() => this._loginWithGoogle()}>
              Sign Up with Google
            </IonButton>
          </IonCard>
        </IonContent>
        <IonButton routerDirection="back" routerLink="/Login">
          Login
        </IonButton>
      </IonPage>
    );
  }
}
export default withRouter(SignUp);

//this._setUpNewProducts()
