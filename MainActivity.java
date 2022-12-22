package com.example.zadanie_2;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

private TextView A, B, act, Est;
private EditText Result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        A = findViewById(R.id.A);
        B = findViewById(R.id.B);
        act = findViewById(R.id.act);
        Result = findViewById(R.id.result);
        Est = findViewById(R.id.estimation);
        int a = 1 + (int)(Math.random() * ((99 - 1) + 1));
        int b = 1 + (int)(Math.random() * ((99 - 1) + 1));
        int i = (int)(Math.random() * (30 + 1));
        A.setText(String.valueOf(a));
        B.setText(String.valueOf(b));
        if (i<10)
            act.setText("+");
        else if(i > 10 && i < 20)
            act.setText("-");
        else
            act.setText("*");
    }

    @SuppressLint("SetTextI18n")
    public void check(View view) {
        if(String.valueOf(Result.getText())!="") {
        int result = Integer.parseInt (String.valueOf(Result.getText()));
            int est = calculate();
            if (est == result)
                Est.setText("Верно! Правильный ответ: " + est);
            else
                Est.setText("Ошибка! Правильный ответ: " + est);
        }
    }

    public void next(View view) {
        int a = 1 + (int)(Math.random() * ((99 - 1) + 1));
        int b = 1 + (int)(Math.random() * ((99 - 1) + 1));
        int i = (int)(Math.random() * (30 + 1));
        A.setText(String.valueOf(a));
        B.setText(String.valueOf(b));
        if (i<10)
            act.setText("+");
        else if(i > 10 && i < 20)
            act.setText("-");
        else
            act.setText("*");
        Est.setText("");
        Result.setText("");
    }

    public int calculate () {
        int a = Integer.parseInt ((String) A.getText());
        int b = Integer.parseInt ((String) B.getText());
        int est;
        if (act.getText() == "+")
            est = a + b;
        else if (act.getText() == "-")
            est = a - b;
        else
            est = a * b;
        return est;
    }

}
