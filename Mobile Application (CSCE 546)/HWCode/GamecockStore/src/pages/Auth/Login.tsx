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
import React from "react";
import { toast } from "../../components/toast";
import {
  checkCurrentUser,
  isStoreOwner,
 // signInGoogle1,
  googleSignIn
} from "../../App";
import { db, provider } from "../../App";
import { defaultOrders } from "../../redux/react-redux";
import { withRouter } from "react-router";

export interface LoginProps {
  history: any;
  location: any;
  match: any;
}
export interface LoginState {
  email: "";
  password: "";
  currentUser: "";
}

export async function googleSignin() {
  if (firebase.auth()) {
    await firebase.auth().signOut();
  }
  try {
    await firebase
      .auth()
      .signInWithPopup(provider)
      .then(function(result: any) {
        var token = result.credential.accessToken;
        var user = result.user;
        console.log(user.uid);
        return user;
      })
      .then((userInfo: any) => {
        db.collection("users")
          .doc(userInfo.uid)
          .get()
          .then(async (user: any) => {
            if (user.exists) {
              console.log("This user exists already in the DB");
            } else {
              let userData = {
                orders: [],
                storeOwner: true
                //products: defaultProductIDs
              };
              // Add user data to users collection with doc id of uid
              db.collection("users")
                .doc(userInfo.uid)
                .set(userData)
                .then(() => toast("Updated Google User Data"))
                .catch(error => console.log(error));
            }
            return true;
          });
      })
      .catch(function(error) {
        var errorCode = error.code;
        console.log(errorCode);
      });
  } catch (error) {
    console.log(error);
    return false;
  }
}

class Login extends React.Component<LoginProps, LoginState> {
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
    try {
      await firebase
        .auth()
        .signInWithEmailAndPassword(email, password)
        .then((currentUser: any) => this.setState1(currentUser))
        .catch((error: any) => toast(error.message));
      return true;
    } catch (error) {
      console.log(error.errorCode);
      return false;
    }
  }

  async _loginWithEmailAndPassword(email: any, password: any) {
    const res: any = await this.handleLogin(email, password);
    if (res) {
      this.props.history.replace("/ProductListPage", null);
    } else {
      console.log("Error Logging In With Email!");
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
                this._loginWithEmailAndPassword(
                  this.state.email,
                  this.state.password
                )
              }
              routerDirection="forward"
            >
              Login
            </IonButton>

            <IonButton
              onClick={() => this._loginWithGoogle()}
              routerDirection="forward"
            >
              Login with Google
            </IonButton>
          </IonCard>
          <IonButton onClick={() => checkCurrentUser()}>Check User</IonButton>
        </IonContent>
        <IonButton routerLink="/SignUp">Sign Up</IonButton>
      </IonPage>
    );
  }
}

export default withRouter(Login);

//this._setUpNewProducts()
