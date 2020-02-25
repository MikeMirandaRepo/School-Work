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
  IonButton,
  IonItem,
  IonInput,
  IonList,
  IonLabel
} from "@ionic/react";
import { Link } from "react-router-dom";
import firebase from "firebase";
import React from "react";
import { db } from "../../App";

export interface SignUpProps {}

export interface SignUpState {
  email: "";
  password: "";
}

export default class SignUp extends React.Component<SignUpProps, SignUpState> {
  constructor(props: SignUpProps) {
    super(props);

    this.state = {
      email: "",
      password: ""
    };
  }

  handleSignUp = () => {
    firebase
      .auth()
      .createUserWithEmailAndPassword(this.state.email, this.state.password)
      // TODO: Change StudentHomeScreen to variable to manage teacher signup
      .then((data: any) => {
        // on success, create user data
        let userData = {
          email: this.state.email,
          orders: ["9wgmBDb0TLW2rhe8e8Yw"],
          products: ["9Se1atQ3mibsfWpUrlxK"]
        };
        // Add user data to users collection with doc id of uid
        db.collection("users")
          .doc(data.user.uid)
          .set(userData)
          .then(() => alert("added a User"));
        // .catch(error => this.setState({ errorMessage: error.message })); () => this.props.navigation.navigate("Login")
        // Return object with user creation success
      });
  };

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
          </IonCard>
        </IonContent>
        <IonButton routerDirection="back" routerLink="/Login">
          Login
        </IonButton>
      </IonPage>
    );
  }
}

//this._setUpNewProducts()
