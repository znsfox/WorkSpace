package com.example.demo;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

/**
 * @FileName: CoExampleTest
 * @author: qianBaoLi
 * @date: 2020/11/9 15:51
 * @Description: null
 */
@SpringBootTest
@RunWith(SpringRunner.class)
public class CoExampleTest {
    @Autowired
    private CoExample coExample;

    @Test
    public void getAll() {
        System.out.println(coExample.getAddress());
        System.out.println(coExample.getAge());
        System.out.println(coExample.getName());
    }
}
