package com.example.demo;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

/**
 * @FileName: MultiYmlDemoApplicatoinTests
 * @author: qianBaoLi
 * @date: 2020/11/9 16:23
 * @Description: null
 */
@SpringBootTest
@RunWith(SpringRunner.class)
public class MultiYmlDemoApplicatoinTests {
    @Value("${myenvironment.name}")
    private String name;
    @Test
    public void getMyEnvironment() {
        System.out.println(name);
    }
}
