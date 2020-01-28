import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonList,
  IonItemSliding,
  IonButton,
} from "@ionic/react";
import React, { useState } from "react";

type Page ={
  name: string
  path: string
}

const pages : Page[] = [
  {
    name: "Button",
    path: "/ButtonPage"
  },
  {
    name: "ExampleRoute",
    path: "/ExampleRoute"
  },
  {
    name: "Input",
    path: "/InputPage"
  },
  {
    name: "ScrollableList",
    path: "/ScrollableList"
  },
  {
    name: "Login Page",
    path: "/LoginPage"
  },
  {
    name: "Register",
    path: "/RegisterPage"
  }
];

const Home: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle class="ion-text-center">Hub of All new Pages</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <IonList class="ion-text-center">
          {pages.map((element, i) => (
            <IonItemSliding>
              <IonButton routerLink={pages[i].path} >
                Click to go to the {pages[i].name} Page
              </IonButton>
            </IonItemSliding>
          ))}
        </IonList>
      </IonContent>
    </IonPage>
  );
};

export default Home;








