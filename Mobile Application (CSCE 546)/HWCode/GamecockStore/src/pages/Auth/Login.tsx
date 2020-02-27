import {
  IonCard,
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
import { db } from "../../App";
import React from "react";
import { toast } from "../../components/toast";
import { checkCurrentUser } from "../../App";

export interface LoginProps {}
export interface LoginState {
  email: "";
  password: "";
  currentUser: "";
}

export default class Login extends React.Component<LoginProps, LoginState> {
  constructor(props: LoginProps) {
    super(props);
    this.state = { email: "", password: "", currentUser: "" };
  }

  setState1 = (state: any) => {
    this.setState({ currentUser: state });
    toast(`Set the State to: ${state}`);
  };

  async handleLogin(email: string, password: string) {
    if (firebase.auth()) {
      await firebase.auth().signOut();
    }
    const login = await firebase
      .auth()
      .signInWithEmailAndPassword(email, password)
      .then((currentUser: any) => this.setState1(currentUser))
      .catch((error: any) => toast(error.message));
  }
  public render() {
    return (
      <IonPage>
        <IonHeader>
          <IonToolbar>
            <IonTitle>Login</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent>
          <IonCard>
            <IonList>
              <IonInput
                placeholder="Email"
                type="email"
                onIonChange={(e: any) =>
                  this.setState({ email: e.detail.value })
                }
              />
              <IonInput
                placeholder="Password"
                type="password"
                onIonChange={(e: any) =>
                  this.setState({ password: e.detail.value })
                }
              />
            </IonList>

            <IonButton
              onClick={() =>
                this.handleLogin(this.state.email, this.state.password)
              }
              routerDirection="forward"
              routerLink="/ProductListPage"
            >
              Login
            </IonButton>
          </IonCard>
          <IonButton onClick={() => checkCurrentUser()}>Check User</IonButton>
        </IonContent>
        <IonButton routerLink="/SignUp">Sign Up</IonButton>
      </IonPage>
    );
  }
}

//this._setUpNewProducts()
