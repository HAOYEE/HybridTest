import React, { Component } from 'react';
import {Text, View, TouchableHighlight, StyleSheet, AlertIOS} from 'react-native';

import {NativeModules} from 'react-native'
var vc = NativeModules.SetupViewCtrl;


const onBtnPress = ()=>{
	vc.encodeBase64("react-native调用原生", (result,base64String)=>{
                 if (!result) {
                   console.error(result);
                 } else {
                   console.log(base64String);
                   AlertIOS.alert(
 'encode successed',
 base64String,
 [
    {
      text: "Cancel",
      onPress: () => console.log("Cancel Pressed"),
      style: "cancel"
    },
    {
      text: "Install",
      onPress: () => console.log("Install Pressed")
    }
  ]
);
                 }
           });
};

export default class HybridTest extends Component{
  render() {
    return (
      <TouchableHighlight onPress={onBtnPress} style={styles.container}>
          <Text style={styles.text}>点击 </Text>
      </TouchableHighlight>
    );
  }
}

const styles = StyleSheet.create({
text: {
  flex: 1,
  marginTop: 55,
  fontWeight: 'bold',
  fontSize: 30
},
container: {
        width:300,
        height:300,
        justifyContent:'center',
        alignItems:'center'
    }
});

// AppRegistry.registerComponent('HybridTest', () => HybridTest);