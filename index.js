/** @format */

import React, { Component } from 'react';
import { name as appName } from './app.json';
import {
    AppRegistry,
    StyleSheet, 
    Text,
    View,
    Image
} from 'react-native';
import Setup from './js/pages/Setup';

AppRegistry.registerComponent('HybridTest', () => Setup);
