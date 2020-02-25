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
import { wait } from "@testing-library/react";

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

  handleLogin = () => {
    firebase
      .auth()
      .signInWithEmailAndPassword(this.state.email, this.state.password)
      .then((currentUser: any) => this.setState1(currentUser))
      .catch((error: any) => alert(error.message));
    //firebase.auth().signOut();
  }; //() => this.props.navigation.navigate("StudentHome")


  setState1 = (state: any) => {
    this.setState({currentUser: state});
    console.log(state)
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
            <Link
              onClick={() => this.handleLogin()}
              to={{
                pathname: "/ProductListPage",
                state: { currentUser: this.state.currentUser }
              }}
              style={{ textDecoration: "none" }}
            >
              <IonButton>Login</IonButton>
            </Link>
          </IonCard>
        </IonContent>
        <IonButton routerLink="/SignUp">Sign Up</IonButton>
      </IonPage>
    );
  }
}

//this._setUpNewProducts()
