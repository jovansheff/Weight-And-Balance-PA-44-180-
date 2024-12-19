function calculate() {
  //Basic Empty Weight
  var emptyWeight = document.getElementById('emptyWeight').value;
  var emptyMoment = document.getElementById('emptyMoment').value;
  var cg = emptyMoment / emptyWeight;
  arm.value = cg.toFixed(2);
  //Pilot/Front Passengers
  var w1 = document.getElementById('w1').value;
  var m1 = w1 * 80.5;
  result1.value = m1.toFixed(2);
  //Passengers - Aft Seats
  var w2 = document.getElementById('w2').value;
  var m2 = w2 * 118.1;
  result2.value = m2.toFixed(2);
  //Baggage Area
  var w3 = document.getElementById('w3').value;
  var m3 = w3 * 142.8;
  result3.value = m3.toFixed(2);
  //Fuel (6lbs/gal)
  var w4 = document.getElementById('w4').value;
  var m4 = w4 * 95.0;
  result4.value = m4.toFixed(2);
  //Ramp Weight
  var ramp1 = document.getElementById('ramp1');
  var rampWeight = Number(emptyWeight)+Number(w1)+Number(w2)+Number(w3)+Number(w4);
  ramp1.value = rampWeight.toFixed(2);
  var ramp2 = document.getElementById('ramp2');
  var rampMoment = Number(emptyMoment)+Number(m1)+Number(m2)+Number(m3)+Number(m4);
  ramp2.value = rampMoment.toFixed(2);
  var ramp3 = document.getElementById('ramp3');
  var rampCg = rampMoment / rampWeight;
  ramp3.value = rampCg.toFixed(2);
  //Take-off Weight/CG
  var to1 = document.getElementById('to1');
  var takeoffWeight = rampWeight - 16;
  to1.value = takeoffWeight.toFixed(2);
  var to2 = document.getElementById('to2');
  var takeoffMoment = rampMoment - 1520;
  to2.value = takeoffMoment.toFixed(2);
  var to3 = document.getElementById('to3');
  var takeoffCg = takeoffMoment / takeoffWeight;
  to3.value = takeoffCg.toFixed(2);
  //Estimated Fuel Burn
  var weight5 = document.getElementById('w5').value;
  var moment5 = weight5 * 95.0;
  result5.value = moment5.toFixed(2);
  //Landing Weight/CG
  var landing1 = document.getElementById('landing1');
  var landingWeight = takeoffWeight - weight5;
  landing1.value = landingWeight.toFixed(2);
  var landing2 = document.getElementById('landing2');
  var landingMoment = takeoffMoment - moment5;
  landing2.value = landingMoment.toFixed(2);
  var landing3 = document.getElementById('landing3');
  var landingCg = landingMoment / landingWeight;
  landing3.value = landingCg.toFixed(2);
  //Actual A/C & Change in Basic Empty
  var actualEmptyWeight = document.getElementById('actualEmptyWeight').value;
  var changeWeight = actualEmptyWeight - emptyWeight;
  change1.value = changeWeight.toFixed(2);
  var actualEmptyMoment = document.getElementById('actualEmptyMoment').value;
  var changeMoment = actualEmptyMoment - emptyMoment;
  change2.value = changeMoment.toFixed(2);
  //New Takeoff Wt/CG
  var newTo1 = document.getElementById('newTo1');
  var newTakeoffWeight = takeoffWeight + changeWeight;
  newTo1.value = newTakeoffWeight.toFixed(2);
  var newTo2 = document.getElementById('newTo2');
  var newTakeoffMoment = takeoffMoment + changeMoment;
  newTo2.value = newTakeoffMoment.toFixed(2);
  var newTo3 = document.getElementById('newTo3');
  var newTakeoffCg = newTakeoffMoment / newTakeoffWeight;
  newTo3.value = newTakeoffCg.toFixed(2);
  //New Landing Wt/CG
  var newlanding1 = document.getElementById('newlanding1');
  var newLandingWeight = landingWeight + changeWeight;
  newlanding1.value = newLandingWeight.toFixed(2);
  var newlanding2 = document.getElementById('newlanding2');
  var newLandingMoment = landingMoment + changeMoment;
  newlanding2.value = newLandingMoment.toFixed(2);
  var newlanding3 = document.getElementById('newlanding3');
  var newLandingCg = newLandingMoment / newLandingWeight;
  newlanding3.value = newLandingCg.toFixed(2);
}
