import streamlit as st
import pandas as pd

st.title("Ultrasonic Distance Warning System")

distance = st.slider(
    "Distance (cm)", 2, 100, 50
)

st.metric("Object Distance", f"{distance} cm")

# TASK 2: Change the threshold to 30
if distance < 20:
    st.error("WARNING: Object Too Close!")
    st.write("Red LED: ON")
else:
    st.success("SAFE DISTANCE")
    st.write("Red LED: OFF")

data = pd.DataFrame({
    "Distance (cm)": [50, 30, 25, 10]
})

st.dataframe(data)
st.line_chart(data, y="Distance (cm)")
