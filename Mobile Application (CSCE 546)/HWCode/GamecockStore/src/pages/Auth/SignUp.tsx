import {
  IonCard,
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonButton,
  IonInput,
  IonList,
} from "@ionic/react";
import { Link } from "react-router-dom";
import firebase from "firebase";
import React from "react";
import { db } from "../../App";
import { defaultProducts, defaultOrders, defaultOrderIDs, defaultProductIDs } from "../../redux/react-redux";
import { toast } from "../../components/toast";

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
      .then((data: any) => {
        // on success, create user data
        let userData = {
          email: this.state.email,
          orders: defaultOrderIDs,
          products: defaultProductIDs
        };
        // Add user data to users collection with doc id of uid
        db.collection("users")
          .doc(data.user.uid)
          .set(userData)
          .then(() => toast("Created a User"))
          .catch(error => console.log(error));
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
