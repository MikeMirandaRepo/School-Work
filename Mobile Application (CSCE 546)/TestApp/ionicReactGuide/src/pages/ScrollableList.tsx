import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonItemOption,
  IonAvatar,
  IonToolbar,
  IonList,
  IonItem,
  IonText,
  IonLabel,
  IonItemSliding,
  IonItemOptions,
  IonButton,
  IonIcon,
  IonInput,
  IonBackButton
} from "@ionic/react";
import React, { useState } from "react";
import { star } from "ionicons/icons";

const arr = [
  {
    name: "Finn",
    desc: "Tried to kill Himself"
  },
  {
    name: "Han",
    desc: "Has a Dumb Son"
  },
  {
    name: "Rey",
    desc: "Who my parents"
  }
];


const ScrollableList: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonButton slot="start">
            <IonBackButton />
          </IonButton>
          <IonTitle class="ion-text-center">Ionic Title in a Toolbar</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <IonList>
          {arr.map((element, i) => (
            <IonItemSliding>
              <IonItem>
                <IonAvatar>
                  <img
                    src={`https://ionicframework.com/docs/demos/api/list/avatar-${element.name.toLowerCase()}.png`}
                  ></img>
                </IonAvatar>

                <IonLabel>
                  <h2>{element.name}</h2>
                  <p>{element.desc}</p>
                </IonLabel>
              </IonItem>

              <IonItemOptions side="start">
                <IonItemOption onClick={() => alert("pressed Option")}>
                  {" "}
                  Hello{" "}
                </IonItemOption>
              </IonItemOptions>
            </IonItemSliding>
          ))}
        </IonList>
      </IonContent>
    </IonPage>
  );
};

export default ScrollableList;
